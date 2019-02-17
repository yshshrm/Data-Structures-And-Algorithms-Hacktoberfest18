### Pre-requisites:
#### Install Git: 
*Are you a first time user and just beginning with Open-Source projects? No problem! Here's [how you can install Git on your computer](https://www.digitalocean.com/community/tutorials/how-to-contribute-to-open-source-getting-started-with-git)*

### After you are done installing Git on your computer:

1. Fork this repository on Github.
2. Clone it onto your computer by opening terminal and running
```sh 
$ git clone https://github.com/{your username}/Data-Structures-And-Algorithms-Hacktoberfest18.git
```
3. Use the actual name of the repository to change into that directory
```sh
$ cd repository
```
4. Create and switch to a new branch 
```sh
$ git checkout -b new-branch
```
5. After modifying existing files or adding new files to the project, add them locally to your repository
```sh
$ gid add -A
```
6. Add a short message about what you contributed for
```sh
$ git commit -m "Commit message"
```
7. Fetch changes from parent repository **kvaluruk/Data-Structures-And-Algorithms-Hacktoberfest18** to local repository
```sh
$ git remote add upstream https://github.com/kvaluruk/Data-Structures-And-Algorithms-Hacktoberfest18.git
$ git fetch upstream
```
8. Merge the changes from `upstream` to local
```sh
$ git checkout master
$ git merge upstream/master
```
9. Merge the changes from `master` to `new-branch`
```sh
$ git checkout new-branch
$ git merge master
```
10. Now push the changes to the current branch of your forked repository
```sh
$ git push --set-upstream origin new-branch
```
11. Now you can create a Pull Request with the chosen branch as `new-branch`
