/*
Tenemos un polinomio de segundo grado (ax² + bx + c), donde a, b y c son números reales. 
La fórmula para encontrar sus raíces (los valores de x para que la expresión valga 0) es la siguiente:
x = −b ± √(b² − 4ac) / 2a
Varios casos son posibles. El discriminante (Δ = b² − 4ac) puede valer 0, en cuyo caso hay un único valor 
que hace 0 la ecuación; puede ser positivo y entonces tenemos dos soluciones; o puede ser negativo y 
entonces no hay ninguna solución real. Escriba una función que calcule las raíces de una ecuación de este 
tipo. Utilice una enumeración para tratar separadamente los tres casos, incluso el caso de que no hay soluciones.
*/

#[derive(Debug)] // Permite que un tipo pueda ser impreso fácilmente usando {:?} o {:#?} en un println! o format!
enum Raices {
    Dos(f64, f64),
    Una(f64),
    Ninguna,
}

fn calcular_raices(a: f64, b: f64, c: f64) -> Raices {
    let discriminante = b.powi(2) - 4.0 * a * c;

    if discriminante > 0.0 {
        let x1 = (-b + discriminante.sqrt()) / (2.0 * a);
        let x2 = (-b - discriminante.sqrt()) / (2.0 * a);
        Raices::Dos(x1, x2)
    } else if discriminante == 0.0 {
        let x = -b / (2.0 * a);
        Raices::Una(x)
    } else {
        Raices::Ninguna
    }
}

fn main(){
    let a = 1.0;
    let b = -3.0;
    let c = 2.0;

    match calcular_raices(a, b, c) {
        Raices::Dos(x1, x2) => {
            println!("Siendo a=1, b=-3 y c=2:");
            println!("Las raíces son: {} y {}", x1, x2);
        },
        Raices::Una(x) => {
            println!("Siendo a=1, b=-3 y c=2:");
            println!("La raíz es: {}", x);
        },
        Raices::Ninguna => {
            println!("Siendo a=1, b=-3 y c=2:");
            println!("No hay soluciones reales");
        },
    }

    let a = 2.0;
    let b = -4.0;
    let c = 2.0;

    match calcular_raices(a, b, c) {
        Raices::Dos(x1, x2) => {
            println!("Siendo a=2, b=-4 y c=2:");
            println!("Las raíces son: {} y {}", x1, x2);
        },
        Raices::Una(x) => {
            println!("Siendo a=2, b=-4 y c=2:");
            println!("La raíz es: {}", x);
        },
        Raices::Ninguna => {
            println!("Siendo a=2, b=-4 y c=2:");
            println!("No hay soluciones reales");
        },
    }

    let a = 1.0;
    let b = 2.0;
    let c = 5.0;

    match calcular_raices(a, b, c) {
        Raices::Dos(x1, x2) => {
            println!("Siendo a=1, b=2 y c=5:");
            println!("Las raíces son: {} y {}", x1, x2);
        },
        Raices::Una(x) => {
            println!("Siendo a=1, b=2 y c=5 :");
            println!("La raíz es: {}", x);
        },
        Raices::Ninguna => {
            println!("Siendo a=1, b=2 y c=5:");
            println!("No hay soluciones reales");
        },
    }
}
