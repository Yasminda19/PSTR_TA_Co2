<?php

use Illuminate\Http\Request;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:api')->get('/user', function (Request $request) {
    return $request->user();
});


/*
|--------------------------------------------------------------------------
| API CO2 Monitoring
|--------------------------------------------------------------------------
|
| This section is place for api that related to CO2 Monitoring that will
| be used to send data over JSON to android mobile.
|
*/
Route::prefix('co2')->group(function () {
    /**
     * --------------------------------------------------------------------------
     *  Available Route
     * --------------------------------------------------------------------------
     *  Request         Path        Function    
     *  GET             '/'         See all data
     *  GET             '/{id}'     See spesific data
     *  POST            '/'         Upload new data
     *  DELETE          '/{id}'     Delete existing data
     */
    Route::get('/','CarbonController@index');
    Route::get('/{id}','CarbonController@show');
    Route::post('/','CarbonController@store');
    Route::delete('/{id}','CarbonController@destroy');
    
});