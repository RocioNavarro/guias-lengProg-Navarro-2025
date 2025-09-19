// Defina una struct Punto que represente un punto en el plano.
struct Punto {
    x: f64,
    y: f64,
}

// Defina una función a continuación que reciba tres instancias de Punto y determine si los tres puntos están alineados.
// Calculo la pendiente de una recta formada entre p1 y p2 y luego la comparo con la pendiente de una recta formada por el p2 y p3.

// Si la función recibe por referencia (p1: &Punto), la función solo presta acceso de lectura (no modifica el ownership). 
// Así, el Punto original sigue estando disponible después de la llamada. 
fn estan_alineados(p1: &Punto, p2: &Punto, p3: &Punto) -> bool {
    (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x)
}

fn main() {
    let p1 = Punto { x: 1.0, y: 2.0 };
    let p2 = Punto { x: 2.0, y: 3.0 };
    let p3 = Punto { x: 3.0, y: 4.0 };
    let p4 = Punto { x: 3.0, y: 5.0 };

    println!("¿Están alineados p1, p2, p3? {}", estan_alineados(&p1, &p2, &p3)); // true
    println!("¿Están alineados p1, p2, p4? {}", estan_alineados(&p1, &p2, &p4)); // false
}