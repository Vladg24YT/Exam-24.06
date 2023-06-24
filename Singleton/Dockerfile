FROM ubuntu
LABEL author="Владислав Горский"

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install build-essential gcc make -y

WORKDIR /MyProj_221-3210_Gorskii/
COPY *.cpp /MyProj_221-3210_Gorskii/
COPY *.h /MyProj_221-3210_Gorskii/

RUN make 

ENTRYPOINT ["./my_Program"]
