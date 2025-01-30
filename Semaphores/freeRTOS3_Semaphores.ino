#include <Arduino_FreeRTOS.h>
#include <semphr.h>
long debouncing_time = 150; 
volatile unsigned long last_micros;
SemaphoreHandle_t interruptSemaphore;
void setup() {
  pinMode(2, INPUT_PULLUP);
  xTaskCreate(TaskLed,  "Led", 128, NULL, 0, NULL );
xTaskCreate(TaskBlink,  "LedBlink", 128, NULL, 0, NULL );
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL) {
    attachInterrupt(digitalPinToInterrupt(2), debounceInterrupt, LOW);
  }
}
void loop() {}
void interruptHandler() {
  xSemaphoreGiveFromISR(interruptSemaphore, NULL);
}
void TaskLed(void *pvParameters)
{
  (void) pvParameters;
  pinMode(8, OUTPUT);
  for (;;) {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS) {
      digitalWrite(8, !digitalRead(8));
    }
  }
}
void TaskBlink(void *pvParameters)
{
  (void) pvParameters;
  pinMode(7, OUTPUT);
  for (;;) {
      digitalWrite(7, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(7, LOW);
      vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
void debounceInterrupt() {
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    interruptHandler();
    last_micros = micros();
  }
}