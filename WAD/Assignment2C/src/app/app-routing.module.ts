import {NgModule} from '@angular/core';
import {RouterModule, Routes} from '@angular/router';
import {RegisterComponent} from "./register/register.component";
import {LoginComponent} from "./login/login.component";
import {UserDataComponent} from "./user-data/user-data.component";
import {User} from "./models/user";

const routes: Routes = [
	{path: "", redirectTo: "login", pathMatch: "full"},
	{path: "login", component: LoginComponent, title: "Login"},
	{path: "register", component: RegisterComponent, title: "Register"},
	{path: ":username", component: UserDataComponent, title: "UserData"}
];

@NgModule({
	imports: [RouterModule.forRoot(routes)],
	exports: [RouterModule]
})
export class AppRoutingModule {
}
