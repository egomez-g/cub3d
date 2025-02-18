# cub3D - My First RayCaster with miniLibX

## Descripción

cub3D es un proyecto inspirado en el legendario juego **Wolfenstein 3D**, el primer FPS de la historia. El objetivo es desarrollar una representación gráfica en 3D de un laberinto utilizando la técnica de **Ray-Casting**, permitiendo al jugador explorar el entorno en primera persona.

## Requisitos
- **Necesitamos tener make instalado**
- **SO:** macOS.
- **Compilador:** `gcc` con los flags `-Wall -Wextra -Werror`.

## Características
- Implementado en **C** utilizando **miniLibX**.
- Generación de un entorno 3D basado en un archivo de configuración `.cub`.
- Movimiento del jugador mediante teclas **W, A, S, D**.
- Rotación de la vista con **flechas izquierda/derecha**.
- Gestión de colisiones con paredes.
- Soporte para diferentes texturas de paredes dependiendo de su orientación (**Norte, Sur, Este, Oeste**).
- Configuración de colores personalizados para el suelo y el techo.
- Minimapa en tiempo real.
- Puertas que pueden abrirse y cerrarse.
- Movimiento del punto de vista con el ratón.
- Sprites animados.

## Instalación
1. Clonar el repositorio:
   ```sh
   git clone https://github.com/egomez-g/cub3d.git
   cd cub3D
   ```
2. Compilar el proyecto:
   ```sh
   make
   ```
3. Ejecutar el programa con un archivo de mapa:
   ```sh
   ./cub3D maps/map.cub
   ```

## Formato del Archivo .cub
El archivo de configuración define las texturas y el mapa del laberinto. Ejemplo:
```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```
- `NO`, `SO`, `WE`, `EA`: Definen las texturas de las paredes.
- `F` y `C`: Colores del suelo y techo en formato RGB.
- `1`: Pared, `0`: Espacio vacío, `N/S/E/W`: Posición inicial del jugador y dirección.

## Controles
- `W/A/S/D`: Moverse hacia adelante, izquierda, atrás y derecha.
- `←/→`: Rotar la vista.
- `ESC`: Cerrar el juego.

---
