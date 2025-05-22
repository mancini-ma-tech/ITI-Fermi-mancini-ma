var studente = {
                  nome: "Paolo",
                  cognome: "Rossi",
                  classe: "3BIF",
                  inf: 6,
                  k: 1,

                  info: function() {
                      return  ;
                  },

                  voto: function(){
                    const vote = document.getElementById("vote").value;
                    const resultDiv = document.getElementById("result");
                    resultDiv.innerHTML = "";
                    if (vote >= 6) {
                resultDiv.innerHTML =
                  '<img src="..//..//MEDIA/fel.gif" alt="Promosso" class="emoji happy" /> OTTIMO';
              }
              else {
                resultDiv.innerHTML =
                  '<img src="..//..//MEDIA/arr.gif" alt="Bocciato" class="emoji angry" />TORNA A STUDIARE!!!';
              }
            }
                  },




            media: function() {
              var m = this.inf  / this.k;
              m = m.toFixed(2);
              document.getElementById("media").innerHTML =
                      document.getElementById("nrv").innerHTML =

                      if(m < 6) {

                      } else {

                      }
                  }