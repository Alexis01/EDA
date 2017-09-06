vueltaAtras (Tupla & sol, int k) {
    prepararRecorridoNivel(k);
    while(!ultimoHijoNivel(k)){
        sol[k] = siguienteHijoNivel(k);
        if (esValida(sol, k)){
            if (esSolucion(sol, k))
                tratarSolucion(sol);
            else
                vueltaAtras(sol, k + 1);
        }
    }
}


vueltaAtrasConMarcaje (Tupla & sol, int k, Marca & marcas) {
    prepararRecorridoNivel(k);
    while(!ultimoHijoNivel(k)){
        sol[k] = siguienteHijoNivel(k);
        if (esValida(sol, k, marcas)){
            if (esSolucion(sol, k))
                tratarSolucion(sol);
            else{
                marcar(marcas, sol, k);
                vueltaAtrasConMarcaje(sol, k + 1, marcas);
                desmarcar(marcas, sol, k);
            }
        }
    }
}