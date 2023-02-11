function passValidation()
{
    var nom = document.getElementById("name").value;
    if(nom.length < 3){
        document.getElementById("err1").innerText = "Le nom doit compter au minimum 3 caractères.";
    }else{
        document.getElementById("err1").innerText = "";
    }

    var prenom = document.getElementById("last_name").value;
    if(prenom.length < 4){
        document.getElementById("err2").innerText = "Le prénom doit compter au minimum 4 caractères."
    }else{
        document.getElementById("err2").innerText = "";
    }

    var tel = document.getElementById("tel").value;
    if(!/[0-9]+/.test(tel)){
        document.getElementById("err3").innerText = "Le téléphone ne doit pas contenir des lettres."
    }else{
        document.getElementById("err3").innerText = "";
    }

    var pass = document.getElementById("pass").value;
    if(!/(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{10,}/.test(pass)){
        document.getElementById("err4").innerText = "Mot de passe faible";
    }else{
        document.getElementById("err4").innerText = "";
    }

    var pass2 = document.getElementById("pass2").value;
    if(pass != pass2){
        document.getElementById("err5").innerText = "Les mots de passe ne correspondent pas"
    }else{
        document.getElementById("err5").innerText = "";
    }
}

document.getElementById("reset").addEventListener("click", function(){
    alert("Reset has been clicked.");
    document.getElementById("err1").innerText = "";
    document.getElementById("err2").innerText = "";
    document.getElementById("err3").innerText = "";
    document.getElementById("err4").innerText = "";
    document.getElementById("err5").innerText = "";
});

function nameValidation()
{
    var nom = document.getElementById("name").value;
    if(/[0-9]+/.test(nom) || nom.length < 3){
        document.getElementById("err1").innerText = "Faux";
    }else{
        document.getElementById("err1").innerHTML = "<span style='color: green;'> Correct </span>";
    }
}