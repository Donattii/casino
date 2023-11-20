# 🪙 DONATI CASINO 🪙

## Cómo Jugar 🏇
### Requisitos Previos
- Asegúrate de tener un compilador de C++ instalado en tu computadora.

### Paso 1: Compilar el Programa
1. Abre una ventana de terminal.
2. Navega al directorio que contiene el código fuente del casino.
```cd ruta/del/codigo```

Ejecuta el siguiente comando para compilar el programa.
```g++ -o casino Jugador.cpp Juego.cpp Ruleta.cpp CarreraCaballos.cpp Blackjack.cpp main.cpp```

### Paso 2: Ejecutar el Casino
Después de compilar con éxito, ejecuta el programa con el siguiente comando.
```./casino```

## 🎰 CONTEXTO 🎰
Bienvenido a Donati Casino, un proyecto destinado a crear conciencia sobre la adicción a las apuestas. A través de esta experiencia, queremos resaltar los riesgos asociados con el juego compulsivo. Aunque brindamos entretenimiento, es crucial recordar que, a largo plazo, la mayoría de los jugadores pierden dinero.

## 🎰 PROYECTO 🎰
Este proyecto en C++ implementa un casino virtual con cuatro juegos populares: ruleta, blackjack, máquina tragamonedas y carrera de caballos. Diseñado para un solo jugador, ofrece una experiencia de juego envolvente y divertida.

## Características

- **Ruleta**: Permite apostar a números y colores mientras la rueda gira.
- **Blackjack**: Juega una mano de cartas contra el crupier.
- **Máquina Tragamonedas**: Gira los rieles y busca combinaciones ganadoras.
- **Carrera de Caballos**: Apuesta en una carrera y observa el resultado.

## Instrucciones

1. **Configuración Inicial**:
   - Ingresa tu nombre y establece tu saldo inicial.
   - Selecciona uno de los cuatro juegos disponibles.

2. **Jugando**:
   - Sigue las instrucciones en pantalla para realizar tus apuestas y jugar.
   - Después de cada juego, se actualizará automáticamente tu saldo.

3. **Personalizaciones Adicionales**:
   - Modifica los valores de apuesta mínima para cada juego según tus preferencias.
   - Considera agregar funciones como estadísticas de juego o un historial de apuestas para mejorar la experiencia.

4. **Requisitos del Proyecto**:
   - Asegúrate de tener un compilador C++ compatible y las librerías estándar de C++ instaladas.

## Estructura del Proyecto

### Clase `Jugador`

- Atributos: `nombre` (string) y `saldo` (float).
- Métodos: `getNombre()`, `getSaldo()`, `apostar(float cantidad)` y `actualizarSaldo(float cantidad)`.

### Clase `Juego` (Clase base abstracta)

- Atributos: `nombre` (string) y `apuestaMinima` (float).

### Clase `Ruleta` (Derivada de `Juego`)

- Atributos adicionales: `numeroGanador` (int).
- Métodos: `apostar(float cantidad)` y `jugar()`.

### Clase `Blackjack` (Derivada de `Juego`)

- Atributos adicionales: `mazo` (vector de cartas).
- Métodos: `apostar(float cantidad)` y `jugar()`.

### Clase `CarreraCaballos` (Derivada de `Juego`)

- Atributos adicionales: `distanciaCarrera` (float).
- Métodos: `apostar(float cantidad)` y `jugar()`.

### UML
![image](https://github.com/Donattii/casino/assets/112676468/6bc5275a-0043-4bef-b3b8-505ed766c0f1)






## Flujo de Ejecución

1. El programa solicita al jugador su nombre y saldo inicial.
2. El jugador elige entre los juegos disponibles.
3. Se instancia el juego seleccionado.
4. El jugador apuesta.
5. El juego se ejecuta, gestionando las apuestas y mostrando los resultados.
6. Se actualiza el saldo del jugador después de cada juego.
7. El jugador puede optar por jugar nuevamente o salir del programa.

- Se debe validar que las apuestas no excedan el saldo disponible del jugador.

###  ♣️ ♥️ ♠️ ♦️
