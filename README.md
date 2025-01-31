# Repositorio de código de la materia IoT

Este repositorio almacena el historial de cambios de cada práctica desarrollada durante el curso de IoT

---

## Tabla de contenido

1. [Requisitos previos](#requisitos-previos)  
2. [Instalación](#instalación)  
3. [Aportar al repositorio](#aportar-al-repositorio) 
4. [Notas importantes](#notas-importantes) 

---

## Requisitos previos

Antes de comenzar, asegúrate de tener los siguientes programas instalados en tu equipo:

1. **Python 3.12.8**:
    - [Descargar Python 3.12.8](https://www.python.org/downloads/release/python-3128/).
    - Puedes revisar la instalación con el sigueinte comando:
      ```bash
      python --version
      ```
2. **Pip (gestor de paquetes de Python, generalmente se instala junto con python)**:
     - Puedes revisar la instalación con el sigueinte comando:
      ```bash
      pip --version
      ```
3. **Tkinter (librería de desarrollo de GUI's en python, generalmente se instala junto con python)**:
    - Puedes revisar la instalación con el sigueinte comando:
      ```bash
      python -m tkinter
      ``` 
4. **Virtualenv (gestor de entornos virtuales)**:
    - Puedes instalar virtualenv mediante pip:
      ```bash
      pip install virtualenv
      ```
5. **Visual Studio Code**:
    - [Visual Studio Code](https://www.arduino.cc/en/software)
    - Extensiones necesarias:
      * Jupyter.
      * Python.
      * Pylance.
        
5. **Arduino IDE**:
    - [Descargar Arduino IDE](https://www.arduino.cc/en/software)
    - Librerías necesarias:
      * **Servo** by Michael Margolis, Arduino.
---

## Instalación

Sigue estos pasos para poder comenzar a desarrollar o probar los programas del repositorio:

1. **Crear y activar el entorno virtual**:  
    Crear el entorno virtual:
    ```bash
    virtualenv [nombre_entorno]
    ```
    Activar el entorno virtual:
    ```bash
    source bin/activate  # En macOS/Linux
    Scripts\activate     # En Windows
    ```
    
2. **Clonar el repositorio**:  
   Clona este repositorio en tu máquina local en la creada con virtualenv:  
   ```bash
   git clone -b [nombre_rama] https://github.com/agus-br/iot.git
   ```
    
3. **Instalar dependencias**:  
    Una vez activado el entorno virtual, instala las dependencias necesarias, estas están listadas en un archivo de texto en la carpeta del repositorio:
    ```bash
    pip install -r requirements.txt
    ```
    
---
   
## Aportar al repositorio
1. **Clona el repositorio (solo la primera vez)**:  
   Si aún no tienes el repositorio en tu máquina local, clónalo con el siguiente comando:  
   ```bash
   git clone -b [nombre_rama] https://github.com/agus-br/iot.git
   
2. **Crea una nueva rama para tus cambios**:    
    Siempre crea una nueva rama para tus aportaciones o cambia a alguna rama de desarrollo, si creas una recuerda usar un nombre descriptivo.
    ```bash
    git branch nombre-rama
    git checkout nombre-rama 

3. **Agrega tus cambios al área de preparación (staging)**:     
    Después de realizar tus modificaciones, agrégalas para prepararlas antes del commit.
    ```bash
    git add . 
    
4. **Confirma tus cambios (commit)**:   
    Realiza un commit con un mensaje descriptivo que explique los cambios realizados.
   ```bash
   git commit -m "Descripción breve de los cambios"
   
5. **Sincroniza con la rama principal antes de subir tus cambios**:     
    Asegúrate de integrar los últimos cambios de la rama remota en tu rama local.
    ```bash
    git pull origin [rama_remota]
    
6. **Resuelve conflictos (si los hay)**:    
    Si aparecen conflictos durante el pull, resuélvelos manualmente y realiza un nuevo commit
    ```bash
    git commit -m "Conflictos resueltos"

7. **Sube tus cambios a la rama remota**:   
    Cuando tu rama esté lista y sincronizada, súbela al repositorio remoto.
    ```bash
    git push origin nombre-rama
    
8. **Crea un Pull Request (PR)**:
    NOTA: Este paso no es necesairo para este repositorio.     
    Ve al repositorio remoto y abre un Pull Request desde tu rama hacia la rama principal. Incluye una descripción clara de tus cambios.
  
10. **Espera revisión y realiza ajustes si es necesario**:
    NOTA: Este paso no es necesairo para este repositorio.    
    Si los revisores solicitan cambios, actualiza tu rama y el Pull Request.
   
## Notas importantes
- Puedes trabajar directamente en la rama de cada unidad libremente.  
- Antes de empezar a desarrollar asegurate de sincronizar tu repositorio local con el repositorio remoto:  
  ```bash
  git checkout [rama_local]
  git pull origin [rama_remota]
