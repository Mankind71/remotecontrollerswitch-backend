from flask import Flask, escape, request
import sqlite3


DATABASE = "remotecontrolled.db"



app = Flask(__name__)


def initDb():
    with open("schema.sql") as f:
        db = sqlite3.connect(DATABASE)
        db.cursor().executescript(f.read())


@app.route('/set/status/')
def setStatus():
    status = request.args.get("status", "off")
    db = sqlite3.connect(DATABASE)
    return status



@app.route('/get/status/')
def getStatus():
    db = sqlite3.connect(DATABASE)
    

    return "ok" 


app.run()
