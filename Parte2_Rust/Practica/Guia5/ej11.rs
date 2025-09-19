// Explique el error en el siguiente programa. Haga alguna modificación en la línea indicada para que funcione. ¿Qué conclusión puede sacar de esto?
// Programa 11

/*
fn main() {
   let t = (String::from("Anton"), String::from("Webern"));
   let _s = t.0;
   println!("{:?}", t); // Modifique sólo esta línea. No use '_s'
}
*/

fn main() {
   let t = (String::from("Anton"), String::from("Webern"));
   let _s = t.0.clone();
   println!("{:?}", t); // Modifique sólo esta línea. No use '_s'
}