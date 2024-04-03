import {Component, OnInit} from '@angular/core';
import {Router} from "@angular/router";
import {User} from "../models/user";
import {UserStorageService} from "../user-storage.service";
import {NgFor} from "@angular/common";
import {NgForm} from "@angular/forms";
import {log} from "@angular-devkit/build-angular/src/builders/ssr-dev-server";

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent implements OnInit{
	user !: User;

	ngOnInit() {
		this.user = new User();
		this.user.email = "";
	}

	constructor(private userStorageService: UserStorageService, private router: Router) {
	}

	login(loginForm: NgForm) {
		// Checking if the user exists
		let isValidUser: boolean = this.userStorageService.validate(loginForm.value);

		if(isValidUser){
			this.router.navigateByUrl(`${loginForm.value['username']}`);
		} else {
			alert('Incorrect username or password');
			loginForm.resetForm();
		}

		// console.log(JSON.stringify(this.userStorageService.getAll()));
	}
}
