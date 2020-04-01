var expect = require("chai").expect;
var tools = require("../lib/tools")
describe("printName()", function(){
    it("should print the last name first",function(){
        var results = tools.printName({first: "Alex",last: "Banks"});
        expect(results).to.equal("Banks, Alex");
    })

});