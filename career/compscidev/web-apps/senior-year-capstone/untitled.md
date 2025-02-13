# Lecture 08: Application Deployment on Cloud, Use Case, and Sprint 1

## Cloud Deployment

### Cloud Architectures

![](<../../../../.gitbook/assets/image (356).png>)

### Cloud Service Providers

![](<../../../../.gitbook/assets/image (357).png>)

### Heroku: Our Cloud Service Provider

* Platform as a service (PaaS)
* Enables developers to build, run, and operate applications on the cloud.
  * Supports ruby, java, node.js, scala, clojure, python, php, go.
* Apps have a unique domain
  * Can be customized with domain names
  * Will be routed to an application container called dyno.
* Deployment via Git Push
* All Heroku services are hosted on Amazon's _EC2_ cloud computing platform.

### Deploying a Web App: Overview

#### App Preparation

1. **Recommended**: Copy the sourcecode into a separate folder in your private repo
2. Init the configuration for the Node.js app (to create the `package.json` file.
3. Install the required npm packages using `npm init`
4. Create a .gitignore file
5. Modify the package.json file to run the app with `$npm start`

#### App Deployment on Heroku

1. Create an app on Heroku
2. Add the created heroku app on Google Cloud Shell
3. `git add/commit/push` to deploy my code.

### More Detailed Steps

#### Create a new folder

![](<../../../../.gitbook/assets/image (359).png>)

#### NPM Init

![](../../../../.gitbook/assets/screenshot_2020-09-22-14.28.26_83xlba.jpg)

#### Deploying on the Shell

![](<../../../../.gitbook/assets/image (360).png>)

![](<../../../../.gitbook/assets/image (362).png>)

![](<../../../../.gitbook/assets/image (361).png>)

## Re-Deploying Your Code

![](<../../../../.gitbook/assets/image (363).png>)

## Analysis to Design Implementation Model Flow

![](<../../../../.gitbook/assets/image (364).png>)

##

## Works Cited

* Dr. Phu Phung's CPS 490 Capstone course.
