FROM gcc:13

WORKDIR /app

COPY . .

RUN g++ main.cpp -o app

CMD ["./app"]
