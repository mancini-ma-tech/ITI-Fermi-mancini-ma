// Wait for the DOM to fully load before executing the script
document.addEventListener("DOMContentLoaded", function () {
  // Retrieve the canvas element and its 2D context
  const canvas = document.getElementById("c1");
  if (!canvas) {
    console.error("Canvas element with ID 'c1' not found.");
    return;
  }
  const ctx = canvas.getContext("2d");

  if (ctx) {
    // Linea ad L: inizio (20, 20) fine (70, 100)
    ctx.beginPath();
    ctx.moveTo(20, 20); // Punto iniziale
    ctx.lineTo(20, 100); // Linea verticale
    ctx.lineTo(70, 100); // Linea orizzontale
    ctx.strokeStyle = "black";
    ctx.stroke();

    // Quadrato pieno: inizio (150, 90), lato 50
    ctx.fillStyle = "green";
    ctx.fillRect(150, 90, 50, 50);

    // Quadrato vuoto: inizio (250, 90), lato 50
    ctx.strokeStyle = "black";
    ctx.strokeRect(250, 90, 50, 50);

    // Cerchio: centro (150, 200), raggio 40
    ctx.beginPath();
    ctx.arc(150, 200, 40, 0, 2 * Math.PI); // Disegna il cerchio
    ctx.strokeStyle = "blue";
    ctx.stroke();

    // Testo: scritta "Hello Canvas" a (50, 300)
    ctx.font = "20px Arial";
    ctx.fillStyle = "purple";
    ctx.fillText("Hello Canvas", 50, 300);

    // Gradiente: rettangolo con gradiente lineare
    const gradient = ctx.createLinearGradient(50, 350, 200, 350);
    gradient.addColorStop(0, "red");
    gradient.addColorStop(1, "yellow");
    ctx.fillStyle = gradient;
    ctx.fillRect(50, 350, 150, 50);
  } else {
    console.error("Unable to retrieve canvas context.");
  }
});
