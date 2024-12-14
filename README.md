# Intérprete de pseudocódigo en español: interpreter

**Autor:** Carlos Lucena Robles  
**Asignatura:** Procesadores de lenguajes 
**Curso:** 2022 - 2023  
**Universidad:** Universidad de Córdoba  
**Grado:** 3º de Ingeniería Informática  

---

## Descripción

Este proyecto tiene como objetivo crear un intérprete de pseudocódigo en español, permitiendo la ejecución dinámica de instrucciones.  

### Funcionamiento general  
1. **Definición del lenguaje:**  
   - Se establecen reglas sintácticas y semánticas específicas para el pseudocódigo.  
2. **Análisis léxico y sintáctico:**  
   - Se utiliza **Flex** para escanear el código fuente y generar tokens.  
   - Se utiliza **GNU Bison** para comprobar que las reglas sintácticas se cumplen y para generar el Árbol de Sintaxis Abstracta (AST).  

## Herramientas utilizadas  
- **Flex:** Analizador léxico que procesa el código fuente.  
- **GNU Bison:** Analizador sintáctico encargado de validar las reglas del lenguaje y generar el AST.  

## Propósito  
Este intérprete facilita la ejecución de pseudocódigo, traduciendo y procesando las instrucciones de manera dinámica para demostrar conceptos de programación.  

## Más información  
Consulta [este archivo](Documentacion_Interprete.pdf) para obtener más información sobre el intérprete.  

---

## Compilación

1. En la carpeta raíz del directorio ejecuta:
```bash
make
```
	
2. Para borrar los archivos de compilación:
```bash
make clean
```

Para generar la documentación:
```bash
make doc
```

---

## Ejecución

Una vez compilado el intérprete utilizando el comando `make` desde el directorio raíz (puede aparecer un "warning" si se compila con una versión antigua de `g++`), se generará el ejecutable `interpreter` en la raíz del proyecto.

El intérprete puede ejecutarse de dos maneras:

### Modo interactivo
Desde una terminal, ejecuta el archivo `interpreter`. Una vez iniciado, estará listo para recibir sentencias directamente.

### Modo fichero
Desde una terminal, ejecuta el archivo `interpreter` pasándole como argumento un archivo de texto con extensión `.p`. Por ejemplo:

```bash
./interpreter archivo.p
```

---

##  Estructura proyecto

```bash
interpreter/
├── ast
│   ├── ast.cpp
│   ├── ast.hpp
│   └── makefile
├── error
│   ├── error.cpp
│   ├── error.hpp
│   └── makefile
├── examples
│   ├── Sentencias
│   │   ├── asignacion.p
│   │   ├── case.p
│   │   ├── commands.p
│   │   ├── do_while.p
│   │   ├── escritura.p
│   │   ├── for.p
│   │   ├── if_else.p
│   │   ├── lectura.p
│   │   ├── repeat.p
│   │   └── while.p
│   ├── binario.p
│   ├── conversion.p
│   ├── divisores.p
│   └── menu.p
├── includes
│   └── macros.hpp
├── parser
│   ├── interpreter.l
│   ├── interpreter.y
│   ├── makefile
│   ├── y.gv
│   ├── y.tab.c
│   └── y.tab.h
├── table
│   ├── builtin.cpp
│   ├── builtinFunction.cpp
│   ├── builtinFunction.hpp
│   ├── builtin.hpp
│   ├── builtinParameter0.cpp
│   ├── builtinParameter0.hpp
│   ├── builtinParameter1.cpp
│   ├── builtinParameter1.hpp
│   ├── builtinParameter2.cpp
│   ├── builtinParameter2.hpp
│   ├── constant.cpp
│   ├── constant.hpp
│   ├── init.cpp
│   ├── init.hpp
│   ├── keyword.cpp
│   ├── keyword.hpp
│   ├── logicalConstant.cpp
│   ├── logicalConstant.hpp
│   ├── logicalVariable.cpp
│   ├── logicalVariable.hpp
│   ├── makefile
│   ├── numericConstant.cpp
│   ├── numericConstant.hpp
│   ├── numericVariable.cpp
│   ├── numericVariable.hpp
│   ├── stringConstant.cpp
│   ├── stringConstant.hpp
│   ├── stringVariable.cpp
│   ├── stringVariable.hpp
│   ├── symbol.cpp
│   ├── symbol.hpp
│   ├── symbolInterface.hpp
│   ├── table.cpp
│   ├── table.hpp
│   ├── tableInterface.hpp
│   ├── variable.cpp
│   └── variable.hpp
├── Documentacion_Interprete.pdf
├── Doxyfile
├── interpreter.cpp
└── makefile
```

