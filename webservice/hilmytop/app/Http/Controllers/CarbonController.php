<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Carbon;

class CarbonController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $carbons = Carbon::all();

        if($carbons)
        {
            return response()->json($carbons, 200);
        }
        else
        {
            return response()->json(['message' => 'data not found'], 404);
        }
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $carbon = new Carbon;
        $carbon->value = $request['value'];
        $carbon->save();
        
        if($carbon)
        {
            return response()->json(['message' => 'succes'], 200);
        }
        else 
        {
            return response()->json(['message' => 'failed'], 404);
        }
        
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $carbon = Carbon::find($id);

        if($carbon)
        {
            return response()->json($carbon,200);
        }
        else
        {
            return response()->json(['message' => 'data not found'],404);
        }
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $carbon = Carbon::find($id);
        $carbon->delete();

        return response()->json(['message' => 'success'],200);
    }
}
