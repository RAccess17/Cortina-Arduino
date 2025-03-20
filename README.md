![Tec logo](tecnologico-de-monterrey-blue.png)
# Cortina Arduino
Proyecto hecho para la clase de Analisis de Elementos de la Mecatrónica, donde un Arduino controla el funcionamiento de una cortina industrial a escala a partir de comandos enviados por un pequeño programa en LabVIEW.
## Requerimientos
- Arduino UNO R3.
- [Tarjeta para control de motores CC (L293D)](https://www.steren.com.mx/tarjeta-para-control-de-motores-cc-l293d.html) (Necesaria debido al uso de la libreria `AFMotor` hecha por AdaFruit).
- Un motor reductor de 12VCC (En nuestro caso, usamos uno de [Steren](https://www.steren.com.mx/motor-reductor-metalico-con-eje-tipo-d-12-vcc.html)).
- 2 sensores ultrasonicos HC-SR04.
- 2 micro switches con palanca de lamina.
- Un protoboard pequeño para colocar los pull-downs de los sensores.
- 2 resistencias de 10k Ohms.
- Una fuente de poder que suministre por lo menos 6Vcc para el motor.
- Un cable USB-A a USB-B para alimentar al Arduino y comunicarse con este mismo.
## Como usar?
1. Abre el archivo `CODIGO_CHIDO.ino`, compílalo y súbelo al Arduino UNO.
2. Abre el Serial Monitor para asegurarte de que ambos sensores ultrasónicos están funcionando correctamente. Si no detectan entrada, el código asumirá una distancia de 0 y detendrá cualquier comando de movimiento de los motores.
3. Asegúrate de que todo el hardware esté ensamblado y conectado a sus respectivos puertos.
4. Cierra el IDE de Arduino, ya que la entrada Serial solo puede ser leída/controlada por un solo programa a la vez.
5. Ejecuta el archivo `interfazdelacortina.vi` en LabVIEW.
6. Dentro del programa, en el Combo Box que dice `VISA Resource Name`, selecciona el puerto COM correspondiente a tu Arduino.
7. Corre el programa en LabVIEW.

Si al presionar un botón no sucede nada, presiona el botón de STOP. Es posible que aparezca un error, ignóralo y vuelve a ejecutar el programa. Ahora debería funcionar correctamente.
## Creditos
- Rosalía Begoña Gutiérrez Ize - A00572570
- Grecia Saleth Pulido Bernal - A01645819
- Diego Giovanni Castellanos García - A01639992
- Perla Cecilia Renteria Rodríguez - A01645074
- Jorge Eduardo Lerma Álvarez - A01643511 (Yo)
