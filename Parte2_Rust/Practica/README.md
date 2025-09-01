# Guía rápida para compilar y ejecutar archivos Rust

## Compilar un archivo Rust

Para compilar un archivo Rust (por ejemplo, `Ej1.rs`), usa el siguiente comando:

```bash
rustc Ej1.rs
```

Esto generará un ejecutable llamado `Ej1` en la misma carpeta.

## Ejecutar el archivo compilado

Para ejecutar el archivo compilado, usa:

```bash
./Ej1
```

## Ejemplo completo

```bash
rustc Ej2.rs   # Compila el archivo Ej2.rs
./Ej2          # Ejecuta el programa compilado
```

Asegúrate de estar en la carpeta donde se encuentra el archivo `.rs` antes de ejecutar estos comandos.

---

Si tienes varios archivos, repite el proceso para cada uno cambiando el nombre del archivo.

---

## Comandos para guardar y subir cambios con git

Para guardar y subir tus cambios al repositorio remoto, usa:

```bash
git add .
git commit -m "mensaje"
git push origin main
```


