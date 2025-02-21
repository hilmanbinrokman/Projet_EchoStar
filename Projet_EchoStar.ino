
/**
   @brief This example will forward serial signal from the USB to EchoStar module and vice versa.
          In another word, it will by pass the MCU.

          The DPDT RF Switch control signal can be reversed by sending '*' character to the USB USB_SERIAL.

   @author mtnguyen
   @version 1.1.0
*/
#ifndef SENSORS_BME680_ADDRESS
#error This board version do not has BME680, please check again your parameters!
#endif

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h" // https://github.com/adafruit/Adafruit_BME680

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme;

#define SWITCH_REVERSING_CONTROL_DEFAULT_VALUE true
volatile int switch_reversing_control = SWITCH_REVERSING_CONTROL_DEFAULT_VALUE;

void setup(void)
{
  switch_reversing_control = SWITCH_REVERSING_CONTROL_DEFAULT_VALUE;

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

#if defined(ECHOSTAR_PWR_ENABLE_PIN)
  pinMode(ECHOSTAR_PWR_ENABLE_PIN, OUTPUT);
  digitalWrite(ECHOSTAR_PWR_ENABLE_PIN, HIGH);
#endif
  //
  //#if defined(DPDT_PWR_ENABLE_PIN)
  //  pinMode(DPDT_PWR_ENABLE_PIN, OUTPUT);
  //  digitalWrite(DPDT_PWR_ENABLE_PIN, HIGH);
  //#endif
  //  pinMode(DPDT_CTRL_PIN, OUTPUT);
  //  digitalWrite(DPDT_CTRL_PIN, HIGH);
  //
  //  pinMode(ECHOSTAR_SWCTRL_PIN, INPUT);
  //  attachInterrupt(digitalPinToInterrupt(ECHOSTAR_SWCTRL_PIN), swctrl_change_isr, CHANGE);

  USB_SERIAL.println("Starting...");

  //  do_switch_ctrl_update();
  //  USB_SERIAL.print("RF Switch reverse control: ");
  //  USB_SERIAL.println(switch_reversing_control ? "ENABLE" : "DISABLE");

  ECHOSTAR_SERIAL.begin(115200);
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);

  pinMode(SENSORS_PWR_ENABLE_PIN, OUTPUT);
  digitalWrite(SENSORS_PWR_ENABLE_PIN, HIGH);

  Wire.setSDA(SENSORS_I2C_SDA_PIN);
  Wire.setSCL(SENSORS_I2C_SCL_PIN);
  Wire.begin();

  USB_SERIAL.begin(115200);
  USB_SERIAL.println("\nEchoStar BME680 Test");

  if (!bme.begin(SENSORS_BME680_ADDRESS))
  {
    USB_SERIAL.println(F("Could not find a valid BME680 sensor, check wiring!"));
    while (1)
      ;
  }
  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop(void)
{
  if (ECHOSTAR_SERIAL.available())
  {
    USB_SERIAL.write(ECHOSTAR_SERIAL.read());
  }
  //USB_SERIAL.println();

  while (USB_SERIAL.available())
  {
    bool test = false;
    unsigned long endTime = bme.beginReading();
    if (endTime == 0)
    {
      USB_SERIAL.println(F("Failed to begin reading :("));
      return;
    }
    delay(50);
    if (!bme.endReading())
    {
      USB_SERIAL.println(F("Failed to complete reading :("));
      return;
    }
    String t = (String)bme.temperature;
    String p = (String)(bme.pressure / 100.0);
    String h = (String)bme.humidity;
    String g = (String)(bme.gas_resistance / 1000.0);

    while (test == false) {
      ECHOSTAR_SERIAL.print("AT+SEND=1,0,8,1,");
      ECHOSTAR_SERIAL.print(bme.temperature);
      ECHOSTAR_SERIAL.print(" ");
      ECHOSTAR_SERIAL.print(bme.pressure / 100.0);
      ECHOSTAR_SERIAL.print(" ");
      ECHOSTAR_SERIAL.print(bme.humidity);
      ECHOSTAR_SERIAL.print(" ");
      ECHOSTAR_SERIAL.print(bme.gas_resistance / 1000.0);
      ECHOSTAR_SERIAL.println(" ");
      test = true;
    }

    if (test == true)
    {
      USB_SERIAL.print(F("Temperature = "));
      USB_SERIAL.print(bme.temperature);
      USB_SERIAL.println(F(" *C"));
      USB_SERIAL.print(F("Pressure = "));
      USB_SERIAL.print(bme.pressure / 100.0);
      USB_SERIAL.println(F(" hPa"));
      USB_SERIAL.print(F("Humidity = "));
      USB_SERIAL.print(bme.humidity);
      USB_SERIAL.println(F(" %"));

      USB_SERIAL.print(F("Gas = "));
      USB_SERIAL.print(bme.gas_resistance / 1000.0);
      USB_SERIAL.println(F(" KOhms"));

      delay(10000);
    }
  }
}
