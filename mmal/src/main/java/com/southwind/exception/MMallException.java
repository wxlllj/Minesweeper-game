package com.southwind.exception;

import com.southwind.result.ResponseEnum;


public class MMallException extends RuntimeException{
    private ResponseEnum responseEnum;

    public ResponseEnum getResponseEnum() {
        return responseEnum;
    }

    public MMallException(ResponseEnum responseEnum){
        super((responseEnum.getMsg()));
        this.responseEnum=responseEnum;
    }

}
