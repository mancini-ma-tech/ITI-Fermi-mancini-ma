let a = parseInt(prompt("Inserisci il 1° numero:"));
let b = parseInt(prompt("Inserisci il 2° numero:"));

if (!isNaN(a) && !isNaN(b)) {
  let somma = a + b;
  console.log("La somma dei due numeri è:", somma);
  alert(somma);
} else {
  console.log("Per favore, inserisci solo numeri validi.");
}
