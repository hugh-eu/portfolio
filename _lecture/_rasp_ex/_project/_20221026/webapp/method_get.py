from flask import Flask, request, render_template

app = Flask(__name__)

@app.route('/method_get', methods=['GET'])
def method_get():
    return render_template('method_get.html')

@app.route('/method_get_act', methods=['GET'])
def method_get_act():
    if request.method == 'GET':
        id = request.args["id"]
        password = request.args["password"]
        return render_template('method_get.html', id=id, password=password)

if __name__ == "__main__":
    app.run(debug=True, port=5000, host='0.0.0.0')

