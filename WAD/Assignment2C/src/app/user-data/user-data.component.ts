import {Component, OnInit} from '@angular/core';
import {ActivatedRoute, Params} from "@angular/router";
import {User} from "../models/user";
import {UserStorageService} from "../user-storage.service";

@Component({
  selector: 'app-user-data',
  templateUrl: './user-data.component.html',
  styleUrl: './user-data.component.css'
})
export class UserDataComponent implements OnInit {
	user !: User;

	constructor(private route: ActivatedRoute, private userStorageService: UserStorageService) {
	}

	ngOnInit() {
		this.route.params.subscribe((params: Params) => {
			this.user = new User();

			if(params['username']) {
				this.user = this.userStorageService.get(params['username']);
			}
		});
	}
}
