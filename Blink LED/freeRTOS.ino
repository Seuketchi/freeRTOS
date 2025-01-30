#include <Arduino_FreeRTOS.h>

#define LED1 8
#define LED2 9

void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);

void setup() {
  Serial.begin(9600);
  xTaskCreate(TaskBlink1,"Task1",128,NULL,1,NULL);
  xTaskCreate(TaskBlink2,"Task2",128,NULL,1,NULL);
  xTaskCreate(TaskPrint,"Task3",128,NULL,1,NULL);

  vTaskStartScheduler();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskBlink1(void *pvParameters) {
  pinMode(LED1,OUTPUT);
  while(1) {
    Serial.println("Task1");
    digitalWrite(LED1, HIGH);
    vTaskDelay(200/portTICK_PERIOD_MS);
    digitalWrite(LED1, LOW);
    vTaskDelay(200/portTICK_PERIOD_MS);
  }
}

void TaskBlink2(void *pvParameters) {
  pinMode(LED2,OUTPUT);
  while(1) {
    Serial.println("Task2");
    digitalWrite(LED2, HIGH);
    vTaskDelay(200/portTICK_PERIOD_MS);
    digitalWrite(LED2, LOW);
    vTaskDelay(200/portTICK_PERIOD_MS);
  }
}

void TaskPrint(void *pvParameters) {
  int counter = 0;
  while(1) {
    counter++;
    Serial.println(counter);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

