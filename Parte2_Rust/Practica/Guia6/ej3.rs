/*
Ahora redefina su función de manera que sea un método de Punto. 
Este método debe recibir dos instancias de Punto y debe devolver 
true o false dependiendo de que los dos puntos determinen una recta 
que incluya a self.
*/


struct Punto {
    x: f64,
    y: f64,
}

impl Punto {
    // Pasando &self aviso que voy a trabajar sobre una instancia concreta de Punto
    fn estan_alineados(&self, p2: &Punto, p3: &Punto) -> bool {
        (p2.y - self.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - self.x)
    }
}

fn main() {
    let p1 = Punto { x: 1.0, y: 2.0 };
    let p2 = Punto { x: 2.0, y: 3.0 };
    let p3 = Punto { x: 3.0, y: 4.0 };
    let p4 = Punto { x: 3.0, y: 5.0 };

    println!("¿Están alineados p1, p2, p3? {}", p1.estan_alineados(&p2, &p3)); // true
    println!("¿Están alineados p1, p2, p4? {}", p1.estan_alineados(&p2, &p4)); // false
}