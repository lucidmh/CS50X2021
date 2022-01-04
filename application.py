import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

MONTH = [
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12"
    ]

DAY = [
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31"
    ]

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        # there's 3 variuble that we should place them in all birthday and make a table of them in database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")


        # validute the user submission
        if not name or not month or not day:
            message = ("Don't you think there's somethting you forgot?")
            return render_template("index.html", message = message)

        #handle the date
        if month not in MONTH or day not in DAY:
            return render_template("index.html", message = "Don't you think something is wrong with date or month?")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?,?,?)", name, month, day)

    # TODO: Display the entries in the database on index.html
    birthdays = db.execute("SELECT * FROM birthdays")
    return render_template("index.html", birthdays=birthdays)

    if request.method == "GET":
        return render_template("index.html")
