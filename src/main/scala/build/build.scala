package build

import chisel3._
import _root_.circt.stage.ChiselStage
import scala.util.{Try, Success, Failure}

object build {
  def getModule(moduleName: String): RawModule = {
    moduleName match {
      //case "GCD" => new gcd.GCD()
      case "Multiplier" => new mxfp4.Multiplier()
      case "FieldExtractor" => new mxfp4.FieldExtractor()
      case "MulConvert" => new mxfp4.MulConvert()
      case "TOP_MulConvert" => new mxfp4.TOP_MulConvert()
      case "Adder_Dep_1" => new mxfp4.Adder_Dep_1()
      case "Adder_Dep_2" => new mxfp4.Adder_Dep_2()
      case "Adder_Dep_3" => new mxfp4.Adder_Dep_3()
      case "Adder_Dep_4" => new mxfp4.Adder_Dep_4()
      case "Adder_Dep_5" => new mxfp4.Adder_Dep_5()
      case "Adder_Dep_6" => new mxfp4.Adder_Dep_6()
      case "Adder_Dep_7" => new mxfp4.Adder_Dep_7()
      case "Adder_Dep_8" => new mxfp4.Adder_Dep_8() 
      case "p_FieldExtractor" => new mxfp4.proposed.p_FieldExtractor()
      case "p_Multiplier" => new mxfp4.proposed.p_Multiplier()
      case "p_Expansion" => new mxfp4.proposed.p_Expansion()
      case "p_MulConvert" => new mxfp4.proposed.p_MulConvert()
      case "p_TOP_MulConvert" => new mxfp4.proposed.p_TOP_MulConvert()
      case "p_Adder_Dep_1" => new mxfp4.proposed.p_Adder_Dep_1()
      case "p_Adder_Dep_2" => new mxfp4.proposed.p_Adder_Dep_2()
      case "p_Adder_Dep_3" => new mxfp4.proposed.p_Adder_Dep_3()
      case "p_Adder_Dep_4" => new mxfp4.proposed.p_Adder_Dep_4()
      case "p_Adder_Dep_5" => new mxfp4.proposed.p_Adder_Dep_5()
      
      case "p_TOP_Til_Dep_5" => new mxfp4.proposed.p_TOP_Til_Dep_5()
      case "p_Adder_ScaleSum" => new mxfp4.proposed.p_Adder_ScaleSum()
      case "p_Adder_ScaleEmax" => new mxfp4.proposed.p_Adder_ScaleEmax()
      case "p_Convert_Dep_5" => new mxfp4.proposed.p_Convert_Dep_5()

      case "p_Convert_Dep_1" => new mxfp4.proposed.p_Convert_Dep_1()
      case "p_Convert_Dep_2" => new mxfp4.proposed.p_Convert_Dep_2()
      case "p_Convert_Dep_3" => new mxfp4.proposed.p_Convert_Dep_3()
      case "p_Convert_Dep_4" => new mxfp4.proposed.p_Convert_Dep_4()

      case "p_TOP_Til_Dep_All_V1" => new mxfp4.proposed.p_TOP_Til_Dep_All_V1()

      // Every Depth Configurable (Convert)
      case "p_Preprocess_Dep_0" => new mxfp4.proposed.p_Preprocess_Dep_0()
      case "p_Convert" => new mxfp4.proposed.p_Convert(5)
      case "p_TOP_Til_Dep_1_5" => new mxfp4.proposed.p_TOP_Til_Dep_1_5() //need more testing

      // Cross-Block Computation
      case "p_Expansion_Groupwise" => new mxfp4.proposed.p_Expansion_Groupwise(5, 30)
      case "p_NaN_Process" => new mxfp4.proposed.p_NaN_Process(5)
      case "p_Adder_Groupwise" => new mxfp4.proposed.p_Adder_Groupwise(6, 30)
      case "p_Convert_Groupwise" => new mxfp4.proposed.p_Convert_Groupwise(8, 30)


      case "p_TOP_Til_Dep_total" => new mxfp4.proposed.p_TOP_Til_Dep_total()
      case "p_TOP_Til_Dep_total_piped" => new mxfp4.proposed.p_TOP_Til_Dep_total_piped()
      case "p_TOP_Til_Dep_total_piped_CT" => new mxfp4.proposed.p_TOP_Til_Dep_total_piped_CT()
      case "p_TOP_Til_Dep_total_piped_CT_syn" => new mxfp4.proposed.p_TOP_Til_Dep_total_piped_CT_syn()
      case "p_TOP_Til_Dep_total_comb_CT_syn" => new mxfp4.proposed.p_TOP_Til_Dep_total_comb_CT_syn()

      case other =>

        System.err.println(s"❌ Unknown module: $moduleName")
        sys.exit(1)
    }
  }

  def main(args: Array[String]): Unit = {
    if (args.length != 1) {
      println("❌ Usage: sbt runMain build.build <ModuleName>")
      sys.exit(1)
    }

    val moduleName = args(0)
    println(s"✅ Generating Verilog for $moduleName ...")


    val outputDir = "generated/verilog"
    val outputFile = s"$moduleName.sv"

    val result = Try {
      ChiselStage.emitSystemVerilogFile(
        getModule(moduleName),
        args = Array("-td", outputDir),
        firtoolOpts = Array(
          "-disable-all-randomization",
          "-strip-debug-info",
          "-default-layer-specialization=enable",
          "-o", outputFile  
          
        )
      )
    }

    result match {
      case Success(_) =>
        println(s"✅ Done: Check $outputFile")
      case Failure(ex) =>
        println(s"❌ Failed to generate Verilog for $moduleName")
        ex.printStackTrace()
        sys.exit(1)
    }
  }
}
