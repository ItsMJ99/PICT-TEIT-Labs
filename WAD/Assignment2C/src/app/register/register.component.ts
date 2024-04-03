import {Component, OnInit} from '@angular/core';
import {FormBuilder, FormGroup, NgForm, Validators} from "@angular/forms";
import {ActivatedRoute, Router} from "@angular/router";
import {UserStorageService} from "../user-storage.service";
import {User} from "../models/user";

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrl: './register.component.css'
})
export class RegisterComponent implements OnInit {
	// Current user
	user !: User;

	ngOnInit() {
		this.user = new User();
	}

	constructor(private router: Router, private userStorageService: UserStorageService) {
	}

	register(registerForm: NgForm) {
		// Checking if the user already exists
		let isNewUser = this.userStorageService.exists(registerForm.value);

		if(isNewUser) {
			alert('User already exists');
			registerForm.resetForm();
		} else {
			if(registerForm.valid) {
				this.userStorageService.add(registerForm.value);
				this.router.navigateByUrl(`${registerForm.value['username']}`);
				// alert('Form submitted');
			} else {
				alert("Form is invalid");
				registerForm.resetForm();
			}
		}
		// console.log(JSON.stringify(this.userStorageService.getAll()));
	}
}
