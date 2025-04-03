const canvas = document.getElementById("c1");
const ctx = canvas.getContext("2d");
ctx.fillStyle = "blue";
ctx.fillRect(50, 50, 200, 100);
var d = document.getElementById("c1");
if (d && d.getContext) {
  var ctx = d.getContext("2d");
} else {
  console.error("Elemento canvas con ID 'c1' non trovato o non supportato.");
}
