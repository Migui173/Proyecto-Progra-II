cmake_minimum_required(VERSION 4.0)
project(ProyectoProgra)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProyectoProgra main.cpp
        main.cpp
        utils.h
        utils.cpp
        usuario.h
        usuario.cpp
        Zona.h
        Zona.cpp
        Bicicleta.cpp
        Bicicleta.h
        BiElectrica.cpp
        BiElectrica.h
        BiMecanica.cpp
        BiMecanica.h
        Transaccion.h
        Transaccion.cpp
        Supervisor.h
        Supervisor.cpp
        Estacion.h
        Estacion.cpp
        Sistema.h
        Sistema.cpp
        leertxt.cpp)
