//take our whole page and then add a listener to it ,when the dom content has been loaded and make a function named listen that will do something(and we check what this function doing with console log)
document.addEventListener('DOMContentLoaded', function Listen() {
    //make a variable and then choose everything in page that has btn class
    let buttonelement = document.querySelectorAll(".btn");

    //for the next part at first we should make an variable of submit btn of index page for second question
    let checkbtn = document.querySelector("#checkpart2answer");
    //check that we choose correct element
    console.log(checkbtn);

    //variable for stop the user to submit new answers for now it's false(multipate choise)
    let multiplechance = false;

    //variable for stop the user to submit new answers for now it's false(free response)
    let freechance = false;
    //check that buttonelemnt works
    console.log(buttonelement);

    //actually we have the "for i bla bla bla" thing in js to!
    for (let btn of buttonelement) {

        //for each of this button when someone click on them, make an event listener and call another function named multiplechoice
        btn.addEventListener("click", multiplechoice);

        //in this function we're actually check that user answer is correct or not and change back ground color of btn
        function multiplechoice(event) {
            //change the value of multiplechance to true to stop chance of user from make another choise after we got to the end of the loop and see the value of true for this variable(multiplate)
            if (multiplechance == true) {
                return;
            }
            //tips-> with console log(event) we can see a lot of property of js in console log
            //target-> this property actually gives us a refrence to excact html element that we point to
            const currentbtn = event.target;

            //we're saying that if we click on a button that has correct class, go to style and turn it to green
            if (currentbtn.classList.contains("correct")) {
                currentbtn.style.background = "green";
                window.alert("Correct!");
            }
            else {
                currentbtn.style.background = "red";
                window.alert("Incorrect!")
            }
            //change the value of chance of multiplate to true
            multiplechance = true;

        }
        //we're gonna listen to another event in the page that happens when user click the checkbox, and than we call response function
        checkbtn.addEventListener("click", response);

        //we call our function response
        //change the value of multiplechance to true to stop chance of user from make another choise after we got to the end of the loop and see the value of true for this variable(multiplate)
        function response() {
            if (freechance == true) {
                return;
            }
            //make a variable of answerbox and say select the element in our webpage that have part2answer id
            let answerelement = document.querySelector(".part2answer");
            console.log(answerelement);
            //choose the value inside of the textbox
            let answer = answerelement.value;
            console.log(answer);

            //check the
            if (answer =="no country") {
            //change the back ground color to the green if answer is correct
                answerelement.style.background = "green";
                window.alert("Correct!");
            }
            else {
                answerelement.style.background = "red";
                window.alert("Incorrect/try again!");
            }
            //change the value of chance of submit to true
            freechance = true;
            }
    }

});