from machine import Pin
import time

f = Pin(7, Pin.OUT)
g = Pin(5, Pin.OUT)
a = Pin(6, Pin.OUT)
b = Pin(8, Pin.OUT)
e = Pin(2, Pin.OUT)
d = Pin(3, Pin.OUT)
c = Pin(4, Pin.OUT)

# Pines de cátodos (un pin por cada dígito)
catodo_1 = Pin(22, Pin.OUT)
catodo_2 = Pin(14, Pin.OUT)
catodo_3 = Pin(12, Pin.OUT)
catodo_4 = Pin(13, Pin.OUT)

azul = Pin(21, Pin.OUT) # Suma
rojo = Pin(19, Pin.OUT) # Resta

button_digito_1 = Pin(16, Pin.IN)
button_digito_2 = Pin(18, Pin.IN)
button_operacion = Pin(17, Pin.IN)
button_igual = Pin(15, Pin.IN)

counter_d1 = 0
counter_d2 = 0
counter_color = 0
resultado = 0

num_map = {
        0: (1, 1, 1, 1, 1, 1, 0),
        1: (0, 1, 1, 0, 0, 0, 0),
        2: (1, 1, 0, 1, 1, 0, 1),
        3: (1, 1, 1, 1, 0, 0, 1),
        4: (0, 1, 1, 0, 0, 1, 1),
        5: (1, 0, 1, 1, 0, 1, 1),
        6: (1, 0, 1, 1, 1, 1, 1),
        7: (1, 1, 1, 0, 0, 0, 0),
        8: (1, 1, 1, 1, 1, 1, 1),
        9: (1, 1, 1, 1, 0, 1, 1),
        10: (0, 0, 0, 0, 0, 0, 1), # Guion para números negativos
    }

leds = [a, b, c, d, e, f, g]

digits = [catodo_1, catodo_2, catodo_3, catodo_4]

color_map = {
        0: (1, 0),
        1: (0, 1),
    }

colors = [azul, rojo]

def display_color(number):
    """Enciende un color en funcion del contador"""
    for i in range(2):
        colors[i].value(color_map[number][i])

# Apagar todos los cátodos
def apagar_catodos():
    for digit in digits:
        digit.value(1)

def display_number(number, catodo):
    """Enciende los LEDs correspondientes al número dado"""    
    apagar_catodos()
    digits[catodo - 1].value(0)
    
    for i in range(7):
        leds[i].value(num_map[number][i])
    # Pequeño retardo para multiplexado (ajustar según necesidad)
    time.sleep(0.002)
    

def imprimir_resultado(resultado):
    """Muestra el resultado en el display de 7 segmentos."""
    if resultado > 9:
        # Obtener los dígitos individuales
        decena = resultado // 10  # Primer dígito (decenas)
        unidad = resultado % 10   # Segundo dígito (unidades)

        # Mostrar en los cátodos 3 y 4
        display_number(decena, 3)  # Dígito 3 (decenas)
        display_number(unidad, 4)  # Dígito 4 (unidades)
    elif resultado < 0:
        # Mostrar en los cátodos 3 y 4
        display_number(10, 3)  # Dígito 3 (decenas)
        display_number(resultado * (-1), 4)  # Dígito 4 (unidades)
    else:
        # Si es un solo dígito, mostrarlo en el cátodo 4
        display_number(resultado, 4)
    
def clear_display():
    """Apaga todos los segmentos"""
    for led in [a, b, c, d, e, f, g]:
        led.value(0)

if __name__ == "__main__":
    while True:
        if(resultado != 0):
            counter_d1 = 0
            counter_d2 = 0
            imprimir_resultado(resultado)
        else:
            display_color(counter_color)
            display_number(counter_d1, 1)
            display_number(counter_d2, 2)
            
        if button_digito_1.value():
            resultado = 0
            time.sleep(0.5)
            counter_d1 = (counter_d1 + 1) % 10
            print("Boton 1")
            print(counter_d1)
            
            
        if button_digito_2.value():
            resultado = 0
            time.sleep(0.5)
            counter_d2 = (counter_d2 + 1) % 10
            #display_number(counter_d2, 1)
            print("Boton 2")
            print(counter_d2)
            
            
        if button_operacion.value():
            resultado = 0
            time.sleep(0.5)
            counter_color = (counter_color + 1) % 2
            print("Cambio de operación")
            print(counter_color)
            
        if button_igual.value():
            time.sleep(0.5)
            print("Igual")
            if(counter_color == 0):
                resultado = counter_d1 + counter_d2
            else:
                resultado = counter_d1 - counter_d2
            print(resultado)
            
            

