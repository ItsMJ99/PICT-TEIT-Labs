// Parsing data from url query parameters
let urlParams = new URLSearchParams(window.location.search);
let data = urlParams.get("data");

data = JSON.parse(data);
// Displaying the data
document.getElementById("name").innerHTML = data.name;
document.getElementById("username").innerHTML = data.username;
document.getElementById("mobile").innerHTML = data.mobile;
document.getElementById("email").innerHTML = data.email;
document.getElementById("dob").innerHTML = data.dob;
document.getElementById("gender").innerHTML = data.gender;
document.getElementById("address").innerHTML = data.address;
document.getElementById("state").innerHTML = data.state;
document.getElementById("city").innerHTML = data.city;
document.getElementById("pincode").innerHTML = data.pincode;
document.getElementById("hobbies").innerHTML = data.hobbies;