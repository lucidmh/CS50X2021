
        function check(truue, element) {
            if (truue) {
                document.getElementById(element).innerHTML = "Correct!"
            }
            else {
                document.getElementById(element).innerHTML = "Incorrect"
            }
        }

        function resetButtonsState() {

            var buttons = document.querySelectorAll(".button");
            buttons.forEach(function (button) {
                button.classList.remove('incorrect');
                button.classList.remove('correct');
            })
        }

        function getAnswerButton() {
            resetButtonsState()
            if (event.target.id == "correct") {
                event.target.classList.add('correct');
                check(true, "return_part_1");
            }
            else {
                event.target.classList.add('incorrect');
                check, ("return_part_1");
            }

        }

        document.addEventListener("DOMContentLoaded", function (event) {
            var buttons = document.querySelectorAll(".button");
            buttons.forEach(function (button) {
                button.addEventListener("click", getAnswerButton);
            })

            inputField = document.querySelector('input')
            checkButton = document.querySelector("#check");
            checkButton.addEventListener('click', function (evt) {
                if (inputField.value.toLowerCase() == "switzerland") {
                    check(true, "return_part_2");
                }
                else {
                    check(false, "return_part_2");
                }
            });
        });