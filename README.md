# FreeRTOS-Based Real-Time System Development

## Overview
This repository documents my implementation of **FreeRTOS tasks for real-time embedded development**, specifically focusing on **blinking an LED on an Arduino Uno** using FreeRTOS. This was part of my **Real-Time Development Systems** course. The repository contains:
- Source code for creating FreeRTOS tasks
- Explanations of how the system was implemented
- Photos demonstrating the working setup

---

## **What is FreeRTOS?**
- **FreeRTOS** is a lightweight, real-time operating system (RTOS) designed for **microcontrollers** and small **microprocessors**. It’s perfect for devices with limited memory, compute power, and energy resources.
- **RTOS** ensures **deterministic behavior**, meaning it can handle tasks and events within **strict timing requirements**, making it ideal for **embedded systems** like robots, medical devices, and IoT gadgets.

---

## **How RTOS Differs From General-Purpose OS**

| **Feature** | **RTOS (e.g., FreeRTOS)** | **General OS (e.g., Linux, Windows)** |
|------------|--------------------------|--------------------------------------|
| **Purpose** | Designed for **real-time responses** to external events. | Focused on multi-user support, efficiency, and multitasking. |
| **Determinism** | Guarantees task completion **within deadlines**. | Prioritizes fairness and overall system responsiveness. |
| **Size & Complexity** | Small and lightweight, ideal for low-power devices. | Larger, resource-intensive, requires more memory and CPU. |
| **Task Management** | Operates tasks (similar to threads) but lacks virtual memory. | Handles processes and threads with memory isolation. |
| **Scheduling** | Uses **priority-based scheduling** to meet deadlines. | Uses fairness-based algorithms like round-robin or multilevel. |
| **Use Cases** | Embedded systems, automation, robotics, IoT. | PCs, servers, and multi-purpose devices. |

---

## **Key Features of FreeRTOS**

### 1. Multitasking
- Even with a **single-core processor**, FreeRTOS can manage multiple tasks by switching between them **rapidly**.
- This creates the **illusion of concurrency**, though only one task runs at a time.

### 2. Task Management
- Tasks in FreeRTOS are similar to **threads** in general OSes but **simplified**.
- Example:  
  - In a **robot**, one task can control the **motor**, while another monitors **sensors**—both appear to run **simultaneously**.

### 3. Scheduling
- **General OS**: Tries to divide CPU time fairly among all tasks.
- **FreeRTOS**: Assigns each task a **priority**, ensuring critical tasks execute first.
  - Example: A robot **must stop immediately** when a **sensor detects an obstacle** (high priority) before logging data (low priority).

### 4. Simplified Development
- Multitasking allows breaking complex applications into **smaller, manageable tasks**.
- The RTOS **handles task timing** and coordination, making development **easier**.

---

## **RTOS in Real-Time Systems**

### Deadlines Matter
- In **real-time systems**, missing a **deadline** could lead to **failure** (e.g., a pacemaker not responding in time).
- RTOS scheduling ensures **deadlines** are met by prioritizing **tasks** correctly.

### Example: Autonomous Car
- **High-priority task**: Braking when a **pedestrian crosses**.
- **Low-priority task**: Logging trip data.  
  - FreeRTOS ensures **braking happens immediately** without being delayed by lower-priority tasks.

---

## **Why RTOS is Unique**
- **Deterministic Scheduling**:
  - In FreeRTOS, the **highest-priority** task that is **ready** to execute will **always run**.
  - If tasks have the **same priority**, FreeRTOS **shares CPU time** fairly between them.

### Example of Task Behavior
- **Yield**: A task **voluntarily** gives up the CPU for another task.
- **Sleep (Delay)**: A task **pauses** for a set amount of time.
- **Block**: A task **waits** for an event (e.g., **sensor input**) before continuing.

---

## **Implementation Details**
### 1. System Setup
- **Hardware:** Arduino Uno
- **Software:** Arduino IDE with FreeRTOS library
- **Components:** 
  - LED (connected to a digital pin)
  - Arduino board
  - USB cable for programming

### 2. FreeRTOS Task Creation
The implementation follows these key steps:

1. **Install FreeRTOS Library**  
   - Added FreeRTOS library in Arduino IDE.
   - Included `<Arduino_FreeRTOS.h>` in the program.

2. **Define Task Functions**  
   - Created multiple task functions (`Task1`, `Task2`, etc.).

3. **Create Tasks in `setup()`**  
   - Used `xTaskCreate()` to initialize tasks with priorities.
   - Started the FreeRTOS scheduler with `vTaskStartScheduler()`.

4. **Task Execution & Context Switching**  
   - Tasks execute in **round-robin** or **priority-based scheduling**.
   - Used `vTaskDelay()` instead of `delay()` to maintain FreeRTOS operation.

---

## **Results & Demonstrations**
- The **LED successfully blinks** at predefined intervals.
- The system **efficiently handles multiple tasks** without delay-based blocking.
- Photos of the working setup are available in the repository.

---

## **Repository Contents**
- `src/` → Source code for the FreeRTOS implementation.
- `docs/` → Photos of the setup and results.
- `README.md` → Documentation (this file).

---

## **How to Run**
1. Clone this repository:
   ```sh
   git clone https://github.com/your-username/your-repo.git
2. Open the code in Arduino IDE.
3. Install the FreeRTOS library via the Arduino Library Manager.
4. Upload the code to your Arduino Uno.

---

## **Practical Applications**
 ### When to Use FreeRTOS
- Critical systems with strict timing (e.g., medical devices, robots).
- Devices with limited resources (e.g., IoT devices, microcontrollers).
- Systems requiring predictable responses to external events.
### When NOT to Use FreeRTOS
-General-purpose systems like PCs or smartphones, where multitasking, user interaction, and flexibility are prioritized over strict timing.

---

## **References**
-------------- 
* [FreeRTOS Official Documentation](https://www.freertos.org/)
* [Arduino FreeRTOS Library](https://github.com/feilipu/Arduino_FreeRTOS_Library)
* [FreeRTOS Fundamentals](https://www.freertos.org/Documentation/01-FreeRTOS-quick-start/01-Beginners-guide/01-RTOS-fundamentals)



