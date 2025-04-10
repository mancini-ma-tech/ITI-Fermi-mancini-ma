const alfa = document.getElementById("c1");
const ctx = alfa.getContext("2d");

// Testa
ctx.beginPath();
ctx.arc(150, 150, 100, 0, Math.PI * 2, true);
ctx.fillStyle = "pink";
ctx.fill();
ctx.lineWidth = 3;
ctx.stroke();

// Occhio sinistro
ctx.beginPath();
ctx.arc(110, 130, 20, 0, Math.PI * 2, true);
ctx.fillStyle = "lightblue";
ctx.fill();

// pupilla Occhio sinistro
ctx.beginPath();
ctx.arc(110, 130, 5, 0, Math.PI * 2, true);
ctx.fillStyle = "black";
ctx.fill();

//  Occhio destro
ctx.beginPath();
ctx.arc(190, 130, 20, 0, Math.PI * 2, true);
ctx.fillStyle = "lightblue";
ctx.fill();

//  pupilla Occhio destro
ctx.beginPath();
ctx.arc(190, 130, 5, 0, Math.PI * 2, true);
ctx.fillStyle = "black";
ctx.fill();
// Bocca sotto (sorriso)
ctx.beginPath();
ctx.arc(150, 160, 50, 0, Math.PI, false);
ctx.strokeStyle = "#000";
ctx.lineWidth = 3;
ctx.stroke();
