const express=require('express');
const app=express();
const bodyParser=require('body-parser');
const path=require('path');
const aws = require('aws-sdk');
const multers3 = require('multer-s3');
const multer = require('multer');
const routes={
    newUser:require('./routes/newUser'),
    userLogin:require('./routes/userLogin'),
    admin:require('./routes/admin')
}


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:true}));
app.set('view engine','hbs');
app.set('views',path.join(__dirname,'views'));

app.use(express.static(path.join(__dirname,'public_static')));

app.use('/newUser',routes.newUser);
app.use('/userLogin',routes.userLogin);
app.use('/admin',routes.admin);


app.listen(2335,()=>{
console.log('Server on at http://localhost:2335/');
});