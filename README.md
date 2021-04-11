# arduino-calculator
Калькулятор на Ардуино (Keypad_I2C, LiquidCrystal_I2C)

# Зависимости

Исходный код  
https://github.com/FlyingDaniil/calculator-keypad-lcd-i2c

Библиотека для пленочной клавиатуры (Keypad_I2C - PCF8574, PCF8574A and PCF8575)  
https://github.com/joeyoung/arduino_keypads


# Компоненты

В качестве платы для датчиков используется YFRobot Sensor Shield:

![image](https://user-images.githubusercontent.com/4146998/114298374-c08f1b80-9abe-11eb-81ff-a05ada86b761.png)

Она к сожалению малоизвестная и не ясно где ее описание.

Кратко о ней:

COM это RS232-порт. Довольно малоинтересная штука.  
Пины A6 и A7 достались от Arduino Nano.  
Разъем питания пока не ясный, для входа или вывода...  
IIC это шина I2C. Набор пинов произвольный к сожалению (стандарта нет).  
SD это разъем для подключения SD-карт ридера.  
APC220 разъем для подключения модуля беспроводной связи.  

Вот картинка другого подобного шилда:

![image](https://user-images.githubusercontent.com/4146998/114298430-0b109800-9abf-11eb-8a96-bddfe1072094.png)

Для дисплея используется модуль LCD 1602 с модулем расширителем портов для I2C:

![image](https://user-images.githubusercontent.com/4146998/114298573-b6215180-9abf-11eb-9276-7c3b500c0b95.png)

Подключается к YFRobot Sensor Shield в разъем IIC.

В качестве клавиатуры используется KeyPad 4x4:

![image](https://user-images.githubusercontent.com/4146998/114298628-0ac4cc80-9ac0-11eb-8b42-d96cb2ae896e.png)

Клавиатура подключается к модулю расширителю портов для I2C:

![image](https://user-images.githubusercontent.com/4146998/114298696-5aa39380-9ac0-11eb-9512-86163735a81a.png)

На расширителе есть переключатели. Их надо переключить в нули, чтобы адрес был 0x20 (как в скетче).

В качестве микроконтроллера выбран WavGat Uno R3:

![image](https://user-images.githubusercontent.com/4146998/114298957-883d0c80-9ac1-11eb-8d3e-e1988ea7a345.png)



