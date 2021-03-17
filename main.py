from flask import Flask, escape, request, g
import os
from os import path
from pydoclite import doclite
DATABASE = "remotecontrolled.db"

app = Flask(__name__)
d = doclite.Doclite.Connect(b"remotecontrolled.db")
baseCollection = d.Base()


@app.route('/set/status/')
def setStatus():
    status = request.args.get("status", "off")
    if status != "off" and  status != "on":
        return "off"
    baseCollection.Delete({})
    baseCollection.Insert({"status": status})
    return status


@app.route("/")
def home():
    return "welcome to remote switch"


@app.route('/get/status/')
def getStatus():
    s = baseCollection.Find({})
    for i in s:
        return i.get("status")
    return "off"
