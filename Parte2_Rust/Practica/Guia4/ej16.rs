/*
Cree una estructura según el siguiente esquema, que representan cuentas en su banco:

numCuenta (número entero) nombreTitular (String) apellidoTitular (String) saldoPesos (número real) saldoDolares (número real)

Escriba un programa que agregue algunos clientes ficticios a su banco. Estos clientes tendrán también algunos saldos iniciales.

Escriba un programa que permita efectuar depósitos y extracciones de las cuentas. El programa deberá recibir el nombre de la estructura, un código de operación (por ejemplo, 1 es depósito en pesos, 2 depósito en dólares, 3 extracción en pesos y 4 extracción en dólares) y efectúe la operación con las siguientes condiciones:

se debe modificar de manera acorde el saldo correspondiente con la excepción mencionada abajo;
los descubiertos permitidos son 10000 pesos y 8 dólares;
si la operación no es posible (saldo negativo menor que el descubierto permitido), no se producirán modificaciones.
*/

#[derive(Debug)]
struct Cuenta {
    num_cuenta: i32,
    nombre_titular: String,
    apellido_titular: String,
    saldo_pesos: f64,
    saldo_dolares: f64,
}

impl Cuenta {
    fn deposito_pesos(&mut self, monto: f64) -> Result<f64, String> {
        if monto <= 0.0 {
            return Err("El monto debe ser positivo".to_string());
        }
        self.saldo_pesos += monto;
        Ok(self.saldo_pesos)
    }

    fn deposito_dolares(&mut self, monto: f64) -> Result<(), String> {
        if monto <= 0.0 {
            return Err("El monto debe ser positivo".to_string());
        }
        self.saldo_dolares += monto;
        Ok(())
    }

    fn extraccion_pesos(&mut self, monto: f64) -> Result<(), String> {
        let descubierto_permitido = -10000.0;
        if self.saldo_pesos - monto < descubierto_permitido {
            Err("Fondos insuficientes en pesos".to_string())
        } else {
            self.saldo_pesos -= monto;
            Ok(())
        }
    }

    fn extraccion_dolares(&mut self, monto: f64) -> Result<(), String> {
        let descubierto_permitido = -8.0;
        if self.saldo_dolares - monto < descubierto_permitido {
            Err("Fondos insuficientes en dólares".to_string())
        } else {
            self.saldo_dolares -= monto;
            Ok(())
        }
    }
}

fn main() {
    let mut cuenta = Cuenta {
        num_cuenta: 1,
        nombre_titular: "Ana".to_string(),
        apellido_titular: "Pérez".to_string(),
        saldo_pesos: 5000.0,
        saldo_dolares: 100.0,
    };

    println!("Cuenta inicial: {:?}", cuenta);

    match cuenta.deposito_pesos(2000.0) {
        Ok(_) => println!("Depósito en pesos exitoso"),
        Err(e) => println!("Error: {}", e),
    }

    match cuenta.extraccion_dolares(150.0) {
        Ok(_) => println!("Extracción en dólares exitosa"),
        Err(e) => println!("Error: {}", e),
    }

    println!("Estado final: {:?}", cuenta);
}
