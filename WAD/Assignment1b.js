function registerUser() {
    // event.preventDefault(); 

    var id = document.getElementById("id").value;
    var name = document.getElementById("name").value;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
    var email = document.getElementById("email").value;
    var phone = document.getElementById("phone").value;
    var dob = document.getElementById("dob").value;
    var gender = document.querySelector('input[name="gender"]:checked');
    var address = document.getElementById("address").value;
    var city = document.getElementById("city").value;
    var pincode = document.getElementById("pincode").value;
    var state = document.getElementById("state").value;
    var hobbies = document.querySelectorAll('input[name="hobbies"]:checked');

    if (
        id === "" || name === "" || username === "" || password === "" || email === "" ||
        phone === "" || dob === "" || !gender || address === "" || city === "" ||
        pincode === "" || state === "" || hobbies.length === 0
    ) {
        alert("Please fill in all the required fields.");
        return false;
    }

    if (!id || !/^[a-zA-Z0-9]+$/.test(id)) {
        alert("Please enter a valid ID with only letters and numbers");
        return false;
    }

    if (!name || !/^[a-zA-Z\s]+$/.test(name)) {
        alert("Please enter a valid name with only letters");
        return false;
    }

    if (email.indexOf("@") === -1 || email.indexOf(".") === -1) {
        alert("Please enter a valid email address");
        return false;
    }

    if (!pincode || /\D/.test(pincode) || pincode.length !== 6) {
        alert("Please enter a valid 6-digit pincode");
        return false;
    }

    if (
        !password ||
        password.length < 8 ||
        !/\d/.test(password) ||
        !/[!@#$%^&*(),.?":{}|<>]/.test(password)
    ) {
        alert(
            "Please enter a valid password with at least 8 characters, one digit, and one special character"
        );
        return false;
    }

    // Create user data string
    var userDataString =
        "ID: " + id + "<br>" +
        "Name: " + name + "<br>" +
        "Username: " + username + "<br>" +
        "Email: " + email + "<br>" +
        "Phone: " + phone + "<br>" +
        "DOB: " + dob + "<br>" +
        "Gender: " + gender.value + "<br>" +
        "Address: " + address + "<br>" +
        "City: " + city + "<br>" +
        "Pincode: " + pincode + "<br>" +
        "State: " + state + "<br>" +
        "Hobbies: " + Array.from(hobbies).map(hobby => hobby.value).join(", ");

        $.ajax({
            type: 'POST',
            url: 'https://jsonplaceholder.typicode.com/posts',
            data: JSON.stringify(formData),
            contentType: 'application/json',
            success: function (response) {
                window.location.href = 'Assignment1b_3.html?data=' + encodeURIComponent(JSON.stringify(response));
            },
            error: function (error) {
                console.log('Error:', error)
            }
        })
}

// Hook up the event listener to the form
document.querySelector("form").addEventListener("submit", registerUser);
