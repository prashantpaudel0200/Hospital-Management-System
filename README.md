# 🏥 Hospital Management System

A **console-based Hospital Management System** developed in **C++** using Object-Oriented Programming (OOP) concepts.

The project is designed to manage essential hospital operations such as **patients, doctors, appointments, and billing** while demonstrating practical use of C++ classes, file handling, functions, and modular programming.

---

## 📌 Features

* 👤 **Patient Management**

  * Add new patients
  * View patient records
  * Search and manage patient information

* 👨‍⚕️ **Doctor Management**

  * Add doctor records
  * View doctor information
  * Manage doctor details

* 📅 **Appointment Management**

  * Schedule appointments
  * View appointment records
  * Manage patient-doctor appointments

* 💰 **Billing Management**

  * Generate and manage patient bills
  * Store billing-related information

* 💾 **File Handling**

  * Store hospital records using text files
  * Load and update data without using a database

* 🧩 **Modular Structure**

  * Separate header (`.h`) and implementation (`.cpp`) files
  * Feature-based Git branches for collaborative development

---

## 🛠️ Technologies Used

* **Language:** C++
* **Programming Paradigm:** Object-Oriented Programming (OOP)
* **Data Storage:** Text Files (`.txt`)
* **Version Control:** Git & GitHub
* **Development Environment:** VS Code / Any C++ IDE

---

## 📂 Project Structure

```text
Hospital-Management-System/
│
├── main.cpp
│
├── Patient.h
├── Patient.cpp
│
├── Doctor.h
├── Doctor.cpp
│
├── Appointment.h
├── Appointment.cpp
│
├── Billing.h
├── Billing.cpp
│
├── utils.h
├── utils.cpp
│
├── README.md
│
└── data/
    ├── patients.txt
    ├── doctors.txt
    └── appointments.txt
```

---

## 🌿 Git Branch Structure

The project follows a **feature-branch workflow** to make collaboration easier and keep the `main` branch stable.

```text
main
│
├── feature/patient-management
├── feature/doctor-management
├── feature/appointment-management
├── feature/billing
├── feature/utils
└── documentation/readme
```

### Branch Responsibilities

| Branch                           | Responsibility                               |
| -------------------------------- | -------------------------------------------- |
| `main`                           | Stable and integrated version of the project |
| `feature/patient-management`     | Patient-related classes and functionality    |
| `feature/doctor-management`      | Doctor-related classes and functionality     |
| `feature/appointment-management` | Appointment-related functionality            |
| `feature/billing`                | Billing-related functionality                |
| `feature/utils`                  | Utility/helper functions                     |
| `documentation/readme`           | Project documentation and README             |

---

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone <repository-url>
```

### 2. Navigate to the Project

```bash
cd Hospital-Management-System
```

### 3. Compile the Project

Using `g++`:

```bash
g++ main.cpp Patient.cpp Doctor.cpp Appointment.cpp Billing.cpp utils.cpp -o hospital
```

### 4. Run the Program

On macOS/Linux:

```bash
./hospital
```

On Windows:

```bash
hospital.exe
```

---

## 🧠 OOP Concepts Demonstrated

This project is developed to apply important **C++ Object-Oriented Programming concepts**, including:

* Classes and Objects
* Encapsulation
* Constructors
* Member Functions
* Access Specifiers
* Function Overloading
* Inheritance *(if implemented)*
* Polymorphism *(if implemented)*
* File Handling
* Modular Programming

> The exact concepts used may expand as the project develops.

---

## 💾 Data Storage

The system uses text files to store application data:

```text
data/
├── patients.txt
├── doctors.txt
└── appointments.txt
```

This allows the program to retain records even after the application is closed.

---

## 🤝 Collaboration

This project is developed collaboratively using **Git and GitHub**.

Each major feature is developed in its own branch and later merged into the `main` branch after completion and testing.

### Recommended Workflow

```text
Create Feature Branch
        ↓
Implement Feature
        ↓
Test Feature
        ↓
Commit Changes
        ↓
Push Branch
        ↓
Create Pull Request
        ↓
Review
        ↓
Merge into main
```

---

## 🚧 Project Status

**Status:** 🚧 Under Development

The project is currently being developed feature by feature. Additional functionality, improvements, and testing will be added as development progresses.

---

## 🎯 Project Objective

The main objective of this project is to build a simple but functional **Hospital Management System** while gaining practical experience in:

* C++ programming
* Object-Oriented Programming
* File handling
* Modular code organization
* Git and GitHub collaboration
* Feature-based development
* Team-based software development

---

## 👥 Contributors

* **Prashant Paudel** — Main Developer
* **Ridima** — Contributor
* **Pramanna** — Contributor

---

## 📄 License

This project is developed for **educational purposes** as part of a college project.
