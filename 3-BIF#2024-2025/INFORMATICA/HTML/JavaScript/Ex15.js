// Wait for the DOM to fully load before executing the script
document.addEventListener("DOMContentLoaded", function () {
  // Retrieve the canvas element with ID 'c1'
  var d = document.getElementById("c1");
  if (d && d.getContext) {
    var newCtx = d.getContext("2d"); // Obtain the 2D rendering context
  } else {
    console.error("Canvas element with ID 'c1' not found or not supported.");
  }

  // Retrieve the canvas element and its 2D context
  const canvas = document.getElementById("c1");
  const ctx = canvas ? canvas.getContext("2d") : null;

  if (ctx) {
    // Draw a black rectangle at (100, 100) with dimensions 50x50
    ctx.strokeStyle = "black";
    ctx.strokeRect(100, 100, 50, 50);

    // Draw another black rectangle at (200, 100) with dimensions 50x50
    ctx.strokeStyle = "black";
    ctx.strokeRect(200, 100, 50, 50);

    // Draw a red rectangle at (300, 100) with dimensions 50x50
    ctx.strokeStyle = "red";
    ctx.strokeRect(300, 100, 50, 50);

    // Scale the canvas by a factor of 2 and draw a rectangle
    ctx.scale(2, 2);
    ctx.strokeRect(100, 100, 50, 50);

    // Draw a blue line from the top-left corner to (500, 300)
    ctx.moveTo(0, 0);
    ctx.lineTo(500, 300);
    ctx.strokeStyle = "blue";
    ctx.stroke();
  } else {
    console.error("Unable to retrieve canvas context.");
  }
});
