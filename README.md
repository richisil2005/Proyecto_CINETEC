# CINETEC
La mejor plataforma de Streaming del mercado!!!!!
### Fundadores:
* Santiago Miguel Silva Reyes
* Oscar Renato Guerrero Oblitas
* Jose Espinoza Verano
* Rodrigo Gallegos

## Conoce un poco más de CINETEC:
CINETEC es una innovadora plataforma de streaming diseñada para proporcionar a los usuarios una experiencia óptima al buscar y visualizar sinopsis de películas. Con una interfaz amigable y funcionalidades avanzadas, CINETEC se posiciona como la mejor opción en el mercado. CINETEC fue desplegada el 15 de Julio de 2024 y desde su lanzamiento no ha decrecido su popularidad debido a lo sencillo y óptimo que es visualizar datos de diferentes películas de todo el mundo 

## Funcionalidades Implementadas:

### Carga de Base de Datos 
Este magnífico sistema inicia cargando una base de datos en formato .csv que contiene información detallada sobre diversas películas. Esta base de datos incluye información como títulos, géneros, sinopsis, tags, y más.La información de la base de datos se carga en una estructura de datos optimizada para permitir búsquedas rápidas y eficientes. Esto implica el uso de estructuras como diccionarios y listas enlazadas que facilitan el acceso y manipulación de datos de forma eficiente. Se realizan comprobaciones para asegurar que los datos sean consistentes y completos al momento de la carga, manejando posibles errores como datos faltantes o formatos incorrectos.

### Búsqueda de Películas:
Los usuarios pueden realizar búsquedas de películas de dos maneras principales: por palabra clave/frase y por tags específicos.
#### Búsqueda por Palabra Clave o Frase:
Los usuarios pueden ingresar cualquier palabra clave o frase para buscar películas relacionadas. El programa utiliza algoritmos de búsqueda de texto para encontrar coincidencias en los títulos y descripciones de las películas. Los resultados de búsqueda muestran las cinco películas más relevantes basadas en la coincidencia de texto. 
#### Búsqueda por Tags:
Además de las búsquedas de texto, los usuarios pueden buscar películas por tags específicos como cult, horror, drama, etc. Los tags permiten una categorización más precisa y rápida de las películas basadas en sus géneros o características específicas.

### Visualización de Sinopsis
Al seleccionar una película de los resultados de búsqueda, se muestra la sinopsis detallada de la misma.Los usuarios pueden marcar una película lo que indica su preferencia por esa película y ayuda al algoritmo de recomendaciones a personalizar las sugerencias. La opción ver más tarde permite a los usuarios guardar la película en una lista para visualizarla más tarde. Esta funcionalidad es especialmente útil para gestionar las películas que el usuario planea ver en el futuro.

### Recomendaciones Personalizadas 
El sistema utiliza un algoritmo de recomendación que analiza las películas a las que el usuario ha marcado y sugiere películas similares. Este algoritmo puede considerar diversos factores como géneros, directores, actores, y otros atributos para encontrar películas que coincidan con las preferencias del usuario.

### Manuel Para Empezar Tu Aventura En CINETEC
Con el fin de que te familiarizes con el uso de CINETEC hemos elaborado un video con el cual puedes aprender mejor a usar CINETEC. *Manual videovisual de CINETEC:*

## Bibliografía 
Si quieres aprender mejor sobre la arquitectura de CINETEC y como llegamos a crear esta maravillosa plataforma, te recomendamos observar esta documentación:

* Alexandrescu, A., & Lafferty, D. (2001). *Modern C++ design: Generic programming and design patterns applied* (pp. 85-246). Addison-Wesley.
* Nesteruk, D. (2018). *Design Patterns in Modern C++: Reusable Approaches for Object-Oriented Software Design*. United States: Apress.
* Cormen, T. H., Leiserson, C. E., Rivest, R. L., Stein, C. (2001). *Introduction To Algorithms*. India: MIT Press.
* Garrido Carrillo, A. (2017). *Programación genérica en C++: La biblioteca estándar*. Distribuido por: EUG

## Observaciones
Al momento de cargar un csv, este está mal estructurado es decir que no esta correctamente distribuido entre las celdas, CINETEC no va a tener la capacidad de leer correctamente el csv por lo que la búsqueda de películas no sera muy exacta pero como CINETEC es la mejor plataforma de streaming de todo el Perú si relacionara su búsqueda con una película.


