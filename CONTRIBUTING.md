### Contributing to Data-Structures-And-Algorithms-Hacktoberfest18

this is a guidelines for contributing to Data-Structures-And-Algorithms-Hacktoberfest18 with git commands :

1. Fork repository on GitHub
2. Clone project into your computer by 

   ```
   git clone https://github.com/{your-username}/Data-Structures-And-Algorithms-Hacktoberfest18.git
   ```
3. Change into the new project’s directory
  
   ```
   cd Data-Structures-And-Algorithms-Hacktoberfest18.git
   ```
4. in this stage, you need to set up a new remote that points to the original project so   
   that you can grab any changes and bring them into your local copy. Firstly clock on the link to the original repository – it’s labeled “Forked from” at the top of the GitHub page. This takes you back to the projects main GitHub page, so you can find the “SSH clone URL” and use it to create the new remote, which we’ll call upstream. we ensure we’re on the master branch. Then the git pull command will sync our local copy with the upstream project and the git push syncs it to our forked GitHub project

   ```
   - git remote add upstream  
     https://github.com/kvaluruk/Data-Structures-And-Algorithms-Hacktoberfest18.git
   
   - git checkout master && git push origin master
   - git pull upstream master

   ```
5. Create new branch. You can name your branch whatever you like, but it helps for it to be   
   meaningful. 

   ```
   git checkout -b {your-branch-name}
   ```
6. Add some files in project and commit

   ```
   git add *
   git commit -m "your comment"

7. Push a new branch

   ```
   git push -u origin {your-branch-name}  
   
8. Make Pull Request
  
