function calcolaSomma() {
  const numero1 = parseFloat(document.getElementById("numero1").value);
  const numero2 = parseFloat(document.getElementById("numero2").value);
  const somma = numero1 + numero2;

  document.getElementById("semaforo").innerHTML = "La somma è: " + somma;
}
