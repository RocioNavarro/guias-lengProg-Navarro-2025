/*
Tenemos dos tuplas de n y m enteros respectivamente ordenadas de manera creciente. 
Queremos combinar (merge) los elementos de ambos arreglos en una tercera tupla de m+n elementos 
que debe estar igualmente ordenada. Por ejemplo, si tenemos las tuplas (1, 3, 4, 7) y (1, 2, 2, 8, 11, 14) 
deberíamos obtener la tupla (1, 1, 2, 2, 3, 4, 7, 8, 11, 14).
*/

/*
OBSERVACION:
Como las tuplas en Rust tienen tamaño fijo en tiempo de compilación, no se puede crear una tupla “dinámica”.
Lo que sí podemos hacer es usar vectores (Vec<i32>), que son dinámicos, y pasar los tamaños n y m como parámetros.
*/

// OBS: tengo que declarar asi las tuplas porque no puedo pasar como parametro m y n y luego crearlas con un tamaño dinámico
fn merge_sorted_tuples(
    t1: (i32, i32, i32, i32), 
    t2: (i32, i32, i32, i32, i32, i32)
) -> (i32, i32, i32, i32, i32, i32, i32, i32, i32, i32) {

    // Convierto las tuplas en arrays porque las tuplas en rust no son iterables dinamicamente, no puedo hacer t1.i
    let v1 = [t1.0, t1.1, t1.2, t1.3];
    let v2 = [t2.0, t2.1, t2.2, t2.3, t2.4, t2.5];

    let mut merged = Vec::with_capacity(v1.len() + v2.len());

    let mut i = 0;
    let mut j = 0;

    while i < v1.len() && j < v2.len() {
        if v1[i] <= v2[j] {
            merged.push(v1[i]);
            i += 1;
        } else {
            merged.push(v2[j]);
            j += 1;
        }
    }

    // El while anterior recorre hasta llegar al final de alguna de las tuplas, 
    // estos otros son para terminar de recorrer la tupla que tenga mas elementos
    while i < v1.len() {
        merged.push(v1[i]);
        i += 1;
    }
    while j < v2.len() {
        merged.push(v2[j]);
        j += 1;
    }

    // Retorno los elementos del array en una tupla
    (merged[0], merged[1], merged[2], merged[3], merged[4], merged[5], merged[6], merged[7], merged[8], merged[9])
}

fn main() {
    let t1 = (1, 3, 4, 7);
    let t2 = (1, 2, 2, 8, 11, 14);

    let resultado = merge_sorted_tuples(t1, t2);
    println!("Tupla combinada: {:?}", resultado);
}
