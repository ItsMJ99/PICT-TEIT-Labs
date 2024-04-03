import {Injectable} from '@angular/core';
import {User} from "./models/user";

@Injectable({
	providedIn: 'root'
})

// Service for fetching the user data from local storage
export class UserStorageService {

	// Users array
	users: User[] = new Array<User>();

	constructor() {
	}

	// Function to get all users
	getAll(): User[] {
		return this.users;
	}

	// Function to get user
	get(username: string): User {
		for (let i = 0; i < this.users.length; i++) {
			if (this.users[i].username === username) {
				return this.users[i];
			}
		}
		return new User();
	}

	// Function to add new user
	add(user: User) {
		// console.log("Users before adding new user: " + JSON.stringify(this.users));
		this.users.push(user);
		// console.log("Users after adding new user: " + JSON.stringify(this.users));
	}

	// Function to check if a user already exists
	exists(user: User): boolean {
		for (let i = 0; i < this.users.length; i++) {
			if(this.users[i].username === user.username || this.users[i].email === user.email) {
				return true;
			}
		}
		return false;
	}

	// Function to validate user
	validate(user: User): boolean {
		for (let i = 0; i < this.users.length; i++) {
			if(this.users[i].username === user.username && this.users[i].password === user.password) {
				return true;
			}
		}
		return false;
	}
}
