import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

MONTHS = range(1,13)
DAYS = range(1,32)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        birthday = request.form.get("day")
        birthmonth = request.form.get("month")

        if not request.form.get("name") or birthday in DAYS or birthmonth in MONTHS:
           return redirect("/")

        else:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, birthmonth, birthday)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        person_birthday = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", person_birthday=person_birthday, days=DAYS, months=MONTHS)


# OPTIONAL - REMOVE BIRTHDAY FROM LIST
@app.route("/remove", methods=["POST"])

def remove():

        id = request.form.get("id")
        if id:
            db.execute("DELETE FROM birthdays WHERE id = ?", id)

        return redirect("/")
