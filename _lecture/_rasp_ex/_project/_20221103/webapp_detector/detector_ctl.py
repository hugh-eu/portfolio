import detector_db_op
from flask import Flask, request, render_template, session, flash, jsonify
from datetime import timedelta

app = Flask(__name__)
app.secret_key = "detector secret key"
app.config["PERMANENT_SESSION_LIFETIME"] = timedelta(minutes=10)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/checklogin", methods=["POST"])
def checklogin():
    id = str(request.form["id"])
    password = str(request.form["password"])
    rows = detector_db_op.checkIdAndPwForLogin(id, password)
    if len(rows) == 0:
        flash("입력하신 정보와 일치하는 가입내역이 없습니다.")
        return render_template("index.html")
    elif len(rows) > 0 and rows[0]["u_auth"] == "O":
        session["id"] = id
        detector_db_op.setLoginDate(rows[0]["u_no"])
        flash("로그인 성공.")
        return render_template("streaming.html")
    else:
        flash("해당 아이디는 가입대기 중 입니다.")
        return render_template("index.html")

@app.route("/signup")
def signup():
    return render_template("signup.html")

@app.route("/checksignup", methods=["POST"])
def checksignup():
    id = str(request.form["id"])
    password = str(request.form["password"])
    rows = detector_db_op.checkIdForSignup(id)
    if len(rows) == 0:
        detector_db_op.registId(id, password)
        flash("가입 성공.")
        return render_template("index.html")
    else:
        flash("중복되는 아이디입니다.")
        return render_template("signup.html")

@app.route("/streaming")
def streaming():
    return render_template("streaming.html")

@app.route("/imglist", methods=["GET"])
def imglist():
    rows = detector_db_op.getImgList()
    return render_template("imglist.html", list=rows)

@app.route("/checkimg", methods=["GET"])
def checkimg():
    name = request.args["name"]
    return render_template("checkimg.html", img_name=name)

@app.route('/ajaxMonthly', methods=['POST'])
def ajaxMonthly():
    data = request.get_json()
    month = data["month"]
    rows = {
        "rows": detector_db_op.getImgListMonthly(month)
    }
    return jsonify(result="success", result2=rows)

@app.route('/ajaxDaily', methods=['POST'])
def ajaxDaily():
    data = request.get_json()
    day = data["day"]
    rows = {
        "rows": detector_db_op.getImgListDaily(day)
    }
    return jsonify(result="success", result2=rows)

@app.route("/admin")
def admin():
    rows = detector_db_op.getUserList()
    return render_template("admin.html", list=rows)

@app.route("/changeauth", methods=["GET"])
def changeauth():
    u_no = request.args["u_no"]
    u_auth = request.args["u_auth"]
    if u_auth == "O":
        u_auth = "X"
    else:
        u_auth = "O"
    detector_db_op.changeAuth(u_no, u_auth)
    rows = detector_db_op.getUserList()
    return render_template("admin.html", list=rows)

@app.route("/logout")
def logout():
    try:
        detector_db_op.setLogoutDate(session["id"])
        session.clear()
        return render_template("index.html")
    except Exception as e:
        print("Exception during logout : ", e)
        return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True, port=80, host="0.0.0.0")
